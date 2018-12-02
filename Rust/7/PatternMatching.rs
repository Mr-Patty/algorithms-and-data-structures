use std::io;

fn wildcmp(wild: &str, string: &str) {
    let mut cp : i32;
    let mut mp : i32;
    let mut i = 0;
    let mut j = 0;
    while i != string.len() && wild[j] != '*' {
        if (wild[j] != string[i]) && (wild[j] != '?') { return 0; }
        i += 1;
        j += 1;
    }
    while string[i] != 0
    {
        if wild[j] == '*'
        {
            j += 1;
            if wild[j] == 0 { return 1; }

            mp = j;
            cp = i+1;
        }
        else if (wild[j] == string[i]) || (wild[j] == '?')
        {
            i += 1;
            j += 1;
        }
        else
        {
            j = mp;
            i = cp += 1;
        }

    }

    while wild[j] == '*' { j += 1; }

    return !wild[j];
}

fn main() {
    let mut s1 = String::new();
    io::stdin()
        .read_line(&mut s1)
        .ok()
        .expect("read error");
    let mut s2 = String::new();
    io::stdin()
        .read_line(&mut s2)
        .ok()
        .expect("read error");

}
