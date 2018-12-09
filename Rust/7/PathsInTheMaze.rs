use std::io;
use std::collections::VecDeque;

struct Point {
    x : i32,
    y : i32,
}
//
// impl Point {
//     fn clone(&self) -> Point {
//
//     }
// }

impl Clone for Point {
    fn clone(&self) -> Point {
        Point{x : self.x, y : self.y}
    }
}

struct Labyrinth {
    n : usize,
    m : usize,
    points : VecDeque<Point>,
    points_old : VecDeque<Point>,
    matrix : Vec<Vec<char>>,
    paths : Vec<Vec<i64>>,
    paths_old : Vec<Vec<i64>>,
}

// fn check(sel : &Labyrinth, x : i32, y : i32) -> char {
//     if x < 0 || y < 0 || (x as usize) >= sel.n || (y as usize) >= sel.m {
//         return '+';
//     }
//     return sel.matrix[x as usize][y as usize];
// }

// fn check(sel : &Labyrinth, x : i32, y : i32) -> bool {
//     if x < 0 || y < 0 || (x as usize) >= sel.n || (y as usize) >= sel.m {
//         return true;
//     }
//     return false;
// }

impl Labyrinth {
    fn new(x: usize, y: usize) -> Labyrinth {
        Labyrinth {
            n : x,
            m : y,
            matrix : vec![vec!['+' ; y + 2]; x + 2],
            paths : vec![vec![0; y + 2]; x + 2],
            paths_old : vec![vec![0; y + 2]; x + 2],
            points : VecDeque::new(),
            points_old : VecDeque::new(),
        }
    }
    fn check(&mut self, x : i32, y : i32) -> bool {
        if x < 0 || y < 0 || (x as usize) >= self.n || (y as usize) >= self.m {
            return false;
        }
        return true;
    }

    fn eval(&mut self, x : usize, y : usize) {
        let mut s1 = 0;
        let mut s2 = 0;
        let mut s3 = 0;
        let mut s4 = 0;
        if self.matrix[x][y] == '.' || self.matrix[x][y] == '@' || self.matrix[x][y] == '#' {
            if self.check((x as i32) + 1, y as i32) {
                s1 = self.paths_old[x + 1][y];
                let tmp = Point{x : (x as i32) + 1,  y : y as i32};
                self.points.push_back(tmp);
            }
            if self.check((x as i32) - 1, y as i32) {
                s2 = self.paths_old[x - 1][y];
                let tmp = Point{x : (x as i32) - 1,  y : y as i32};
                self.points.push_back(tmp);
            }
            if self.check(x as i32, (y as i32) + 1) {
                s3 = self.paths_old[x][y + 1];
                let tmp = Point{x : (x as i32),  y : (y as i32) + 1};
                self.points.push_back(tmp);
            }
            if self.check(x as i32, (y as i32) - 1) {
                s4 = self.paths_old[x][y - 1];
                let tmp = Point{x : (x as i32),  y : (y as i32) - 1};
                self.points.push_back(tmp);
            }

            self.paths[x][y] = s1 + s2 + s3 + s4;
                // self.paths_old[i + 1][j] +
                // self.paths_old[i - 1][j] +
                // self.paths_old[i][j + 1] +
                // self.paths_old[i][j - 1];

        }
    }

    fn finding(&mut self, x : i32, y : i32, count : usize) {
        let mut tmp = Point{x : x + 1, y : y};
        self.points_old.push_back(tmp);
        tmp = Point{x : x - 1, y : y};
        self.points_old.push_back(tmp);
        tmp = Point{x : x, y : y + 1};
        self.points_old.push_back(tmp);
        tmp = Point{x : x, y : y - 1};
        self.points_old.push_back(tmp);
        // self.paths[x as usize][y as usize] = 0;
        self.paths_old[x as usize][y as usize] = 1;
        for _k in 0..count {
            loop {
                match self.points_old.pop_front() {
                    Some(point) => self.eval(point.x as usize, point.y as usize),
                    None => break,
                }
            }
            self.points_old = self.points.clone();
            self.paths_old = self.paths.clone();
        }

        // for _k in 0..count {
        //     for i in 1..self.n+1 {
        //         for j in 1..self.m+1 {
        //             if self.matrix[i][j] == '.' || self.matrix[i][j] == '@' || self.matrix[i][j] == '#' {
        //                 self.paths[i][j] =
        //                     self.paths_old[i + 1][j] +
        //                     self.paths_old[i - 1][j] +
        //                     self.paths_old[i][j + 1] +
        //                     self.paths_old[i][j - 1];
        //             }
        //         }
        //     }
        //     self.paths_old = self.paths.clone();
        // }
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
    let k : usize = _ln[2];
    let mut start = Point{x : 1, y : 1};
    let mut end = Point{x : 1, y : 1};
    let mut tab = Labyrinth::new(n, m);

    for i in 1..n+1 {
        let mut string = String::new();
        io::stdin()
            .read_line(&mut string)
            .ok()
            .expect("read error");
        let tmp = &string[0..m];
        for (j, c) in tmp.chars().enumerate() {
            tab.matrix[i][j+1] = c;
            if c == '@' {
                start = Point {x : (i as i32), y : ((j + 1) as i32)};
            }
            if c == '#' {
                end = Point {x : (i as i32), y : ((j + 1) as i32)};
            }
        }
    }
    // tab.paths_old[start.x as usize][start.y as usize] = 1;
    tab.finding(start.x, start.y, k);
    for i in 1..n+1 {
        for j in 1..m+1 {
            print!("{} ", tab.paths_old[i][j]);
        }
        println!(" ");
    }
    println!("{}", tab.paths[end.x as usize][end.y as usize]);
}
