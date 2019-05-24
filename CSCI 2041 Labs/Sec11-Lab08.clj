;===============================================================================
; Assignment: Lab 8
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Nov 1, 2016
;===============================================================================

;; true cases
;(fn [a] a)  
;(fn [a] (fn [] a))  
;(fn [a] (fn [a] a))  
;(fn [a] (fn [b] a))  
;(fn [a] ((fn [b] a) a))  
;(fn [a b] a)  
;(fn [a b] b)  
;(fn [a b] (a (b)))  
;(fn [a b] (a (fn [b] a)))  
;(fn [a b c] (a (fn [d e] (a b)) c))


;; false cases
;a
;(a)
;(a b)
;(fn [] a)
;(fn [a] b)
;(fn [a] (a b))
;(fn [a b] (c (fn [c] (c a))))
;(fn [a b] ((fn [c] (a b)) c))






(def lambda-call?
  (fn [l s]
    (


(def lambda-fn?
  (fn [l s]
    (
    
    
    
    
(def lambda-parameters?
  (fn [p]
    (and (vector? p) (apply distinct? p))))



(def lambda-symbol?
  (fn [n s]
    (some
      (fn [i] (= i n))
      (first s))))

(def lambda?
  (fn [l s]
    (
