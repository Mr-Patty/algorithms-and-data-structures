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

    let N : i32 = _ln[0];
    let M : i32 = _ln[1];
    let K : i32 = _ln[2];

    // io::stdin()
    //     .read_line(&mut numbers)
    //     .ok()
    //     .expect("read error");
    for i in 0..N {

        io::stdin()
            .read_line(&mut numbers)
            .ok()
            .expect("read error");

        let mut set: Vec<i32> = numbers
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        set.sort_unstable();
    }
    // let mut _v: Vec<i32> = numbers
    //     .split_whitespace()
    //     .map(|s| s.parse().unwrap())
    //     .collect();

    // _v.sort_unstable();
    // let m = ;
    // let x_ptr = _v.as_mut_ptr();
    // while i < _n {
    //     println!("{}", m[i]);
    // }
    // println!("{}", amount);
}
