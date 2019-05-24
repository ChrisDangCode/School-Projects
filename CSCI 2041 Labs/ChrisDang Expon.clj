;
; Lab 1
; CSCI 2041 Advanced Programming
; Chris Dang
;

(def epsilon 0.000001) ; Accuracy constant

(def exponential
	(def F 1		; F = 1.0
	(def S 0		; S = 0.0
	(def T 1		; T = 1.0
		(fn [x]			; x must be a real value

			(if			; if T <= epsilon, return S
				(<= T epsilon)
					S
					(+ S T		; S = S + T
					(* T (/ x F	; T = T * (x / F)
					(+ F 1		; F += 1
						(recur (x))))))))))))
