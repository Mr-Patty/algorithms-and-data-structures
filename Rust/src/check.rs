use std::io;

fn main() {
    let mut numbers = String::new();
    let mut tuple = String::new();
    io::stdin()
        .read_line(&mut tuple)
        .ok()
        .expect("read error");
    let _ln: Vec<i32> = tuple
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let _l : i32 = _ln[0];
    let _n : i32 = _ln[1];
    io::stdin()
        .read_line(&mut numbers)
        .ok()
        .expect("read error");
    let mut _v: Vec<i32> = numbers
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    _v.sort_unstable();
    // let m = ;
    // let x_ptr = _v.as_mut_ptr();
    let mut amount = 0;

    let mut start = _v[0];
    // let mut i = 0;
    for i in 0.._n {
        println!("{}", i);
        i += 1;
    }
    // while i < _n {
    //     println!("{}", m[i]);
    // }
    println!("{}", amount);
}
