(*==============================================================================
Chris Dang
* Lab Section 11
* Lab assignment 12
* December 12, 2016 
==============================================================================*)

(* Function: Zeroed
* Tests if list l contains at least one element of 1.
*)
let rec zeroed l = 
	match l with 
	[] -> false |
	h :: t -> h = 0 || zeroed t ;;

(* Function: exponentialing
* Does the work for exponential
*)
let rec exponentialing x f s t =
	if t <= 0.000001 (* epsilon value of 0.000001 *)
	then s 
	else exponentialing x (f +. 1.0) (s +. t) (t *. (x /. f))  ;;


(* Function: exponential
* Exponential stuff
*)	
let exponential x =
	exponentialing x 1.0 0.0 1.0 ;;
	
	