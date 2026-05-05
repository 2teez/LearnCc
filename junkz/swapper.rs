#![allow(dead_code, unused)]
use std::mem::swap;

fn main() {
    let mut v = vec!["tolu", "adigun", "timothy", "java"];
    println!("Before Manual Sorting: {:#?}", v);
    for idx in 1..v.len() {
        if v[idx - 1] > v[idx] {
            //let temp = v[idx - 1];
            //v[idx - 1] = v[idx];
            //v[idx] = temp;
            v.swap((idx - 1), idx);
        }
    }
    println!("After Manual Sorting: {:#?}", v);
    v.sort();
    println!("{:?}", v);
}
