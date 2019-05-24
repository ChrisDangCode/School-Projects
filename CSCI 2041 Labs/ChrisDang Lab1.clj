;
; Lab 1
; CSCI 2041 Advanced Programming
; Chris Dang
;

(def epsilon 0.000001) ; Accuracy constant

(def exponential
	(fn [x]		

      ; F = 1.0
      ; S = 0.0
      ; T = 1.0
      (loop  [F 1 S 0 T 1]


			(if			; if T <= epsilon, return S
				(<= T epsilon)
					S 
          
					;(+ S T		; S = S + T
					;(* T (/ x F)	; T = T * (x / F)
					;(+ F 1		; F += 1
						(recur (+ S T)(* T (/ x F))(+ F 1))))))


;(def square-root
;	(fn [x G H]
;		(if 
;			( < (- G H) epsilon) ; if |G-H| < epsilon, return G
;				G
;			(/ (+ G H) 2
;			(/ x G
;			(recur x))))))
