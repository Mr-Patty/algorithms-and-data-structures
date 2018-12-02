use std::io;
use std::collections::HashMap;

fn main() {
    let mut string = String::new();
    io::stdin()
        .read_line(&mut string)
        .ok()
        .expect("read error");
    let mut max_weight: usize = string.len() - 1;
    let n = ( ((string.len() - 1) as f64) / 2.0).floor() as usize;
    for i in 1..string.len() {
        let mut weights: HashMap<&str, usize> = HashMap::with_capacity(string.len() - (i - 1));
        for j in 0..string.len() - (i - 1) {
            let stat = weights.entry(&string[j..j+i]).or_insert(0);
            *stat += 1;
        }
        for val in weights.values() {
            if val * i > max_weight {
                max_weight = val * i;
            }
        }
    }
    println!("{}", max_weight);
}
