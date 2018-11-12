use std::io;
use std::cmp;

fn get_input() -> String {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).expect("Failed");
    buffer
}

fn main() {
    let n = get_input().trim().parse::<i32>().unwrap();
    // let mut v: Vec<i64> = Vec::new();
    let y = get_input().trim().parse::<i64>().unwrap();
    let mut ans : i64 = y;
    let mut sum : i64 = y;
    let mut min_sum : i64 = cmp::min(0, sum);
    for i in 1..n {
        let x = get_input().trim().parse::<i64>().unwrap();
        sum += x;
        ans = cmp::max(ans, sum - min_sum);
        min_sum = cmp::min(min_sum, sum);
    }

    println!("{}", ans);
}
