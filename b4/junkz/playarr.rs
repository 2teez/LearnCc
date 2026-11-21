#![allow(dead_code, unused)]

use std::error::Error;
use std::fmt::Debug;
use std::str::FromStr;

fn main() {
    let arr: [u32; 9] = [2, 3, 5, 7, 9, 11, 13, 17, 19];
    println!("{:?}, size: {}", arr, arr.len());
    println!("{:0>8b}", 10);
    //
    let age: u8 = getline("34"); //.unwrap_or_else(|| print!("bingo"));
    println!("{:?}", getline::<u8>(get_word("30").expect("can't handle")));
    //
    for data in "67 09 23 ".split_whitespace().collect::<Vec<_>>() {
        println!(
            "{:?}",
            match get_word(data) {
                Some(value) => value,
                None => "none",
            }
        )
    }
}

fn getline<T: std::str::FromStr>(line: &str) -> T
where
    <T as FromStr>::Err: Debug,
{
    let trimmed = line.trim();
    trimmed.parse::<T>().expect("can't parse line")
}

fn get_word(line: &str) -> Option<&str> {
    if line.is_empty() {
        return None;
    }
    Some(line.trim().split_whitespace().next()?)
}
