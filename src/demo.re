Js.log "Hello, BuckleScript and Reason!";

let a = "hej";

Js.log ("sdfasdf" ^ a);

let cells = [
  [true, false, true, false],
  [false, true, true, true],
  [true, false, true, false],
  [false, true, false, true]
];

/* Js.log (List.nth (List.nth cells 0) 1); */
let olle cells x y => List.nth (List.nth cells x) y;

let printCell cell => if cell {"X"} else {" "};

let printRow row => String.concat "" (List.map printCell row);

let printBoard board => String.concat "\n" (List.map printRow board);

let getCell board x y =>
  if (x < 0 || x >= List.length (List.nth board 0) || y < 0 || y >= List.length board) {
    /* False if out of bounds */
    false
  } else {
    /* Otherwise get the value from the matrix */
    List.nth (List.nth cells y) x
  };

let countLivingNeighbors board x y => {
  let topLeft = getCell board (x - 1) (y - 1);
  let topMid = getCell board x (y - 1);
  let topRight = getCell board (x + 1) (y - 1);
  let midLeft = getCell board (x - 1) y;
  let midRight = getCell board (x + 1) y;
  let bottomLeft = getCell board (x - 1) (y + 1);
  let bottomMid = getCell board x (y + 1);
  let bottomRight = getCell board (x + 1) (y + 1);
  let neighbors = [
    topLeft,
    topMid,
    topRight,
    midLeft,
    midRight,
    bottomLeft,
    bottomMid,
    bottomRight
  ];
  List.length (List.filter (fun c => c) neighbors)
};

let shouldLive board y x isAlive => {
  let livingNeighbors = countLivingNeighbors board x y;
  if isAlive {
    switch livingNeighbors {
    | 0 => false
    | 1 => false
    | 2 => true
    | 3 => true
    | _ => false
    }
  } else {
    livingNeighbors == 3
  }
};

let stepRow board y row => List.mapi (shouldLive board y) row;

let step board => List.mapi (stepRow board) board;

Js.log (printBoard cells);

let steppedBoard = step cells;

Js.log "stepping...";

Js.log (printBoard steppedBoard);

Js.log "stepping...";

Js.log (printBoard steppedBoard);

Js.log "stepping...";

let steppedBoard2 = step cells;

Js.log (printBoard steppedBoard2);