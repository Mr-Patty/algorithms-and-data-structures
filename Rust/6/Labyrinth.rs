use std::io;
use std::collections::VecDeque;

struct Point {
    x : i32,
    y : i32,
}

struct Labyrinth {
    n : usize,
    m : usize,
    points : VecDeque<Point>,
    matrix : Vec<Vec<char>>,
    paths : Vec<Vec<i32>>,
}

fn check(sel : &Labyrinth, x : i32, y : i32) -> char {
    if x < 0 || y < 0 || (x as usize) >= sel.n || (y as usize) >= sel.m {
        return '+';
    }
    return sel.matrix[x as usize][y as usize];
}

impl Labyrinth {
    fn new(x: usize, y: usize) -> Labyrinth {
        Labyrinth {
            n : x,
            m : y,
            matrix : vec![vec![' ' ; y]; x],
            paths : vec![vec![4000000; y]; x],
            points : VecDeque::new(),
        }
    }

    fn eval(&mut self, x : usize, y : usize) {
        if check(self, (x as i32) + 1, y as i32) != '+' && self.paths[x + 1][y] > self.paths[x][y] + 1 {
            self.paths[x + 1][y] = self.paths[x][y] + 1;
            let tmp = Point{x : (x as i32) + 1, y : y as i32};
            self.points.push_back(tmp);
        }
        if check(self, (x as i32) - 1, y as i32) != '+' && self.paths[x - 1][y] > self.paths[x][y] + 1 {
            self.paths[x - 1][y] = self.paths[x][y] + 1;
            let tmp = Point{x : (x as i32) - 1, y : y as i32};
            self.points.push_back(tmp);
        }
        if check(self, x as i32, (y as i32) + 1) != '+' && self.paths[x][y + 1] > self.paths[x][y] + 1 {
            self.paths[x][y + 1] = self.paths[x][y] + 1;
            let tmp = Point{x : (x as i32), y : (y as i32) + 1};
            self.points.push_back(tmp);
        }
        if check(self, x as i32, (y as i32) - 1) != '+' && self.paths[x][y - 1] > self.paths[x][y] + 1 {
            self.paths[x][y - 1] = self.paths[x][y] + 1;
            let tmp = Point{x : (x as i32), y : (y as i32) - 1};
            self.points.push_back(tmp);
        }
    }

    fn finding(&mut self, x : i32, y : i32) {
        let tmp = Point{x : x, y : y};
        self.points.push_back(tmp);
        self.paths[x as usize][y as usize] = 0;
        loop {
            match self.points.pop_front() {
                Some(point) => self.eval(point.x as usize, point.y as usize),
                None => break,
            }
        }
    }
}

fn main() {
    let mut tuple = String::new();
    io::stdin()
        .read_line(&mut tuple)
        .ok()
        .expect("read error");
    let _ln: Vec<usize> = tuple
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let n : usize = _ln[0];
    let m : usize = _ln[1];
    let mut start = Point{x : 0, y : 0};
    let mut end = Point{x : 0, y : 0};
    let mut tab = Labyrinth::new(n, m);

    for i in 0..n {
        let mut string = String::new();
        io::stdin()
            .read_line(&mut string)
            .ok()
            .expect("read error");
        let tmp = &string[0..m];
        for (j, c) in tmp.chars().enumerate() {
            tab.matrix[i][j] = c;
            if c == '@' {
                start = Point {x : (i as i32), y : (j as i32)};
            }
            if c == '#' {
                end = Point {x : (i as i32), y : (j as i32)};
            }
        }
    }
    tab.finding(start.x, start.y);

    println!("{}", tab.paths[end.x as usize][end.y as usize]);
}
