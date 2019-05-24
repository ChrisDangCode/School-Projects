(*
Lecture date: 2016_12_7
Chris Dang
OCaml notes
	- Examples
	- Higher Order functions
	- Types
	*)
	
(*	
History
	ISwim - Made by Peter Landin 1966
		"ISwim - If you See What I Mean", 
		ISwim was meant to be "ISWYM - I See What You Mean"
	
	From ISwim came ML
	ML - Robin Milner 1970's, U of Edinburgh
	"Meta Language"
	LCF - something that can prove theorems
	
	From ML came Caml
	"Categorial Abstract Machine Language"
	
	From Caml to OCaml
	OCaml - Xavier Leroy (1968 - _)
	"Object Categorial Abstract Machine Language"
	1996 France INRIA
	
	Current version of Ocaml: 2016
	Version used at UMN is slightly older.
	
OCAML
 - strongly typed langauge
 - terminal "cursor" begins with '#'

1 + 2 * 3 ;;
--> - : int 7

let square x = x * x ;;
val square: int -> int = <fun>

square 3 ;;
- int = 9

sqaure 3.0 ;;
error (expected int, recieved real

Type inference algo:
Ways to deal with types:
1: no types (list, clojure, python)
2: explicit types (C's, Java
3: infered types (OCAML)




let rec fib n = 
	if n < 2
	then n
	else fib(n - 1) + fib(n - 2) ;;




Ocaml has:
booleans: true false
Chars: 'A'
strings: "abc" (note: strings are immutable)
arrays: [| e_0 e_1 ... e_n-1|] - mutable
lists: [ e_0 e_1 ... e_n-1] - immutable








fib n - 1
sum [1 ; 2 ; 3] -> 6

1 :: [2 ; 3] -> [1 ; 2 ; 3] (first element is called head, rest is called tail)










let rec sum l =
	match l with
	[] -> 0 |
	h :: t -> h + sum t ;;







	
	
	
	
	
	
	
Note: Dr. James Moen has a problem with Match:
It is too high level. 
There may be a problem with telling what works and doesn't work with match.

# member 2 [1 ; 2; 3] ;;
-: bool = 2

Note: the below does NOT work:
# let rec member e l = 
	match l with
		[] -> false |
		e :: t -> true |
		h :: t -> member e t ;;

		
The below does work
# let rec member e l = 
	match l with
		[] -> false |
		h :: t -> e = h || member e t ;;
		
Moen: "You have to know a about the pattern matching in order to make it work.
I don't know if this is a good thing or not."
	
	
	

	
	
	
let arith a b = 2 * a + b ;;
val arith: int -> int -> int = <fun>
(this is because the arrow means there is a mapping, and that there are 2 mappings)
Ocaml's type system assumes partial evaluation (curried functions)
f(x, y) = f(x)(y)

# arith 1 2 ;;
-: int = 4
# arith 1 ;;
-: int -> int = <fun>
Essentially returns a curried function.


	
	
	
	
	
	
Now let's try to rewrite map from clojure.
Ex. (map f l)
	(map inc '(1 2 3) => '(2 3 4)
	
	(def map
		(fn [f l]
			( if (empty? l)
			'()
			(cons 
			(f (first l))
			(map f (rest l))))))
			
			
# let rec map f l = 
match l with 
[] -> [] |
h :: t -> f h :: map f t ;;
val map : ('a -> 'b) -> 'a list -> 'b' list = <fun>
First item: "f's type. f is a function that maps a to b"
Second: 	"l's type. l ist a list of a's."
Third:		"result type. result is a list of b's"


# map (function x -> x + 1) [1; 2; 3] ;;
-: int list = [2 ; 3 ; 4]





(def compose
	(fn [f g]
		(fn [x]
			(f (g x)))))
			

# let compose f g = 
(function x ->
	f (g x)) ;;
val compose : ('a -> 'b) -> ('c -> 'a) -> 'c -> 'b = <fun>
first item: f's type" Maps a to b.
second: g's type: maps c to a.
third: result type: maps c to b






OCAML IS POSSIBLY ON THE TEST.
IT MIGHT INVOLVE "Here is a function. What is its type?"













MORE TYPES


Java & and the C's types:
enum {n_1, n_2, ... n_k} n;

ex. enum {positive, negative} sign;
sign x = positive;
x == negative



# type intSign = Positive | Negative ;; 

# let sign n =
	if n >= 0
	then Positive
	else Negative ;;
	
	val sign : int -> intSign = <fun>
	
# sign -1 ;;
-: intSign = Negative

# type number = Int of int | Real of float | Error ;;

# let add n1 n2 =
	match (n1, n2) with 
	(Int i1, Int i2) -> Int(i1 + i2) |
	(Real r1, Int i2) -> Real(r1 +. float i2) |
	(Int i1 , Real r2) -> Real(float i1 +. r2) |
	(Real i1, Real i2) -> Real(r1 +. r2) |
	(Error, _) -> Error |
	(_, Error) -> Error ;;


add Int(5) Real(2.0)
=> Real (7.0)



# type 'a bst = Empty | 
				Node of 'a * 'a bst * 'a bst ;; (* recursive type, inductive type*)
				
# let rec member key tree = 
		match tree with
			Empty -> false |
			Node(otherKey, left, right) -> 
				if key < otherKey
				then member key left
				else if key > otherKey
					then member key right
					else true ;;

val member 'a -> 'a bst -> bool = <fun>					
				



