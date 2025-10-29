#![deny(clippy::all, clippy::pedantic, unused)]

#[derive(Debug)]
struct Point {
    x: f32,
    y: f32,
}

#[derive(Debug)]
struct Position {
    pt: Point,
}

impl Position {
    fn new(x: f32, y: f32) -> Self {
        Self { pt: Point { x, y } }
    }

    fn from_point(pt: Point) -> Self {
        Self { pt }
    }

    fn distance(&self) -> f32 {
        f32::sqrt(self.pt.x * self.pt.x + self.pt.y * self.pt.y)
    }
}

fn main() {
    let pt = Position::new(1.35f32, 0.125f32);
    println!("{:?}", pt.distance());

    let point = Point { x: 3.1, y: 0.67 };
    let pt2 = Position::from_point(point);
    println!("{:?}", pt2.distance());
}
