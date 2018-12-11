use std::io;

struct Point {
    x : i32,
    y : i32,
}

struct Labyrinth {
    n : usize,
    m : usize,
    matrix : Vec<Vec<char>>,
    paths : Vec<Vec<i64>>,
    paths_old : Vec<Vec<i64>>,
}

impl Labyrinth {
    fn new(x: usize, y: usize) -> Labyrinth {
        Labyrinth {
            n : x,
            m : y,
            matrix : vec![vec!['+' ; y + 2]; x + 2],
            paths : vec![vec![0; y + 2]; x + 2],
            paths_old : vec![vec![0; y + 2]; x + 2],
        }
    }

    fn finding(&mut self, count : usize) {
        for _k in 0..count {
            for i in 1..self.n+1 {
                for j in 1..self.m+1 {
                    if self.matrix[i][j] == '.' || self.matrix[i][j] == '@' || self.matrix[i][j] == '#' {
                        self.paths[i][j] =
                            self.paths_old[i + 1][j] +
                            self.paths_old[i - 1][j] +
                            self.paths_old[i][j + 1] +
                            self.paths_old[i][j - 1];
                    }
                }
            }
            self.paths_old = self.paths.clone();
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
    tab.paths_old[start.x as usize][start.y as usize] = 1;
    tab.finding(k);
    println!("{}", tab.paths[end.x as usize][end.y as usize]);
}
