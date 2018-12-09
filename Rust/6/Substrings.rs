use std::io;

fn count(pattern: &[u8], text: &[u8], q: i32, d: i32) -> i32 {
    let mut k = 0;
    let m = pattern.len() - 1;
    let n = text.len() - 1;
    let mut j : usize = 0;
    let mut p = 0;
    let mut t = 0;
    let mut h = 1;
    for _i in 1..m {
        h = (h * d) % q;
    }
    for i in 0..m {
        p = (d * p + (pattern[i] as i32)) % q;
        t = (d * t + (text[i] as i32)) % q;
    }

    for i in 0..(n - m + 1) {

        if p == t {

            for k in 0..m {
                j = k;
                if text[i + k] != pattern[k] {
                    break;
                }
            }
            j += 1;

            if j == m {
                k += 1;
            }
        }

        if  i < n - m {
            t = (d * (t - (text[i] as i32) * h) + (text[i + m] as i32)) % q;

            if t < 0 {
                t = t + q;
            }
        }
    }
    return k;
}

fn main() {
    let mut string = String::new();
    io::stdin()
        .read_line(&mut string)
        .ok()
        .expect("read error");
    // let n = ( ((string.len() - 1) as f64) / 2.0).floor() as usize;
    let mut max : i32 = 0;
    for i in 0..string.len()-1 {
        let m = count(&string[i..string.len()].as_bytes(), &string[..].as_bytes(), 512, 1024) * ((&string[i..string.len()].len() - 1) as i32);
        if m > max {
            max = m;
        }
    }

    println!("{}", max);
}
