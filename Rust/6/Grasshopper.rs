use std::io;

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
    let mut f = vec![0; n + 1];
    f[0] = 1;
    for i in 0..n {
        for j in 0..m {
            if i + j + 1 > n {
                break;
            }
            f[i + j + 1] += f[i];
        }
    }
    println!("{}", f[n]);
}
