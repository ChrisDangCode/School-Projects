;===============================================================================
; Assignment: Lab 5
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Oct. 11, 2016
;===============================================================================


;-------------------------------------------------------------------------------
; thru 
; In: function for continuation, start, end
; sOut: none
;-------------------------------------------------------------------------------
(def thru
  (fn [etc start end]
    (loop
      [index start]
        (if (< index end)
          (do
            (etc index)
              (recur (+ index 1)))))))


;-------------------------------------------------------------------------------
; choosing 
; In: function for continuation, a set, number of values 0-n, 
; number of values in set, remaining vals in set
; Out: none
;-------------------------------------------------------------------------------
(def choosing
  (fn [etc theSet n k e]
    (cond (= k 0)         ; 0 remaining vals to add?
      (etc theSet)        ; print set

    :else
    (thru (fn [arg] (choosing etc (conj theSet arg) n (- k 1) (+ arg 1))) e n))))



;-------------------------------------------------------------------------------
; choosing 
; In: function for continuation, a set, number of values 0-n, number of values in set
; Out: none
;-------------------------------------------------------------------------------
(def choose
  (fn [etc n k]
    (choosing etc '() n k 0)))

; Test cases
;(choose println 0 10)
;(choose println 4 2)
;(choose println 5 3)
;(choose println 5 2)
;(choose println 5 0)
;(choose println 1 10)
