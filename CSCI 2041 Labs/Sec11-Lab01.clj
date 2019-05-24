;
; Lab 1
; CSCI 2041 Advanced Programming
; Chris Dang
;

(def epsilon 0.000001) ; Accuracy constant

(def exponential
	(fn [x]		

      ; T = 1.0
      ; S = 0.0
      ; F = 1.0
      (loop  [S 0.0 T 1.0 F 1.0]


			(if			; if T <= epsilon, return S
				(<= T epsilon)
					S 
          
					; (S = S + T
					; T = T * (x / F)
					; F += 1
						(recur (+ S T)(* T (/ x F))(+ F 1))))))
            
(def abs
  (fn [x]
    (if 
      (< x 0)
        (- x)
        x )))

(def square-root
	(fn [x]
    ; G = x
    ; H = 1.0
    (loop [G x H 1.0]
      (if                   ; if |G - H| < epsilon, return G
        (< (abs (- G H)) epsilon)
        G
        
        ; G = ( G + H ) / 2
        ; H = x / G
        (recur (/ (+ G H) 2.0) (/ x G))))))
