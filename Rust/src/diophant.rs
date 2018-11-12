use std::io;

fn gcd (mut a: i32, b: i32) -> i32 {
    if b != 0 {
        a = gcd (b, a % b);
    }
    a
}

fn main() {
    let mut tuple = String::new();
    io::stdin()
        .read_line(&mut tuple)
        .ok()
        .expect("read error");
    let ln: Vec<i32> = tuple
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let a = ln[0];
    let b = ln[1];
    let c = ln[2];
    if c % gcd(a, b) != 0 {
        println!("No");
        return;
    }
    let mut x = 1;
    let y : i32;
    loop {
        let g = c - a * x;
        if g % b == 0 {
            y = g / b;
            break;
        }
        x += 1;
    }
    println!("{} {}", x, y);
}
