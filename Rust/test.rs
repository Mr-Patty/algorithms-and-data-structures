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
    let x_ptr = _v.as_mut_ptr();
    let mut count = 1;

    unsafe {
        // *x_ptr.offset(0) += _l;
        let mut i = 0;
        while i < _n {
            let start = *x_ptr.offset(i as isize);
            i += 1;
            while i < _n && *x_ptr.offset(i as isize) - start <= 2 * _l {
                i += 1;
            }
            println!("{}", count);
            count += 1;
            println!("{}", count);
        }
        // for i in 1.._n+1 {
            // if *x_ptr.offset((i - 1) as isize) >= *x_ptr.offset(i as isize) - _l {
            //     *x_ptr.offset(i as isize) = *x_ptr.offset((i - 1) as isize);
            // } else if i < _n && *x_ptr.offset((i + 1) as isize) - _l <= *x_ptr.offset(i as isize) + _l {
            //     count += 1;
            //     *x_ptr.offset(i as isize) += _l;
            //     *x_ptr.offset((i + 1) as isize) = *x_ptr.offset(i as isize);
            // } else {
            //     count += 1;
            // }
        // }
    }
    println!("{}", count);
}
