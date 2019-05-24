;===============================================================================
; Assignment: Lab 9
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Nov 8, 2016
;===============================================================================
(declare eulerMore factorial pow next-term remaining-terms sumMore)

; Euler creates infinite series
(def euler
  (fn [x]
    (eulerMore x 0)))

; helper for Euler
(def eulerMore
    (fn [x c]
      (list (/ (pow x c) (factorial c))
          (fn []
            (eulerMore x (inc c))))))


(def factorial
  (fn [n]
    (loop [f 1 m n]
      (if (= m 0)
        f
        (recur (* f m) (- m 1))))))




; pow makes the product from the base value and exponent power
(def pow
  (fn [value expon]
    (loop [product 1 expon expon]
      (if (== expon 0)
        product
        (recur (* value product) (dec expon))))))


; grabs first terms from series created by Euler
(def next-term
  (fn [terms]
    (first terms)))


; returns the rest of the terms of Euler
(def remaining-terms
  (fn [terms]
    ((first (rest terms)))))



; Sums up values of Euler numbers
(def sum
  (fn [terms ep]
    (sumMore terms ep 0)))

; helper for sum
(def sumMore
  (fn [terms ep total]
    (if (< (next-term terms) ep)
      total
      (sumMore (remaining-terms terms) ep (+ total (next-term terms))))))



; test case
;(sum (euler 1.0) 0.000001)


