;===============================================================================
; Assignment: Lab 7
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Oct. 29, 2016
;===============================================================================



(def mostMap
  (fn [stuff]
    (map (fn [n] (list 'if n 1 0)) stuff)))

(def callCount
  (fn [stuff]
    (count stuff)))


(defmacro most
  [& l]
  (let [m (mostMap l) n (callCount l)]
    `(> (+ ~@m) (/ ~n 2))))





(def groupUp
  (fn [S L]
    (list (list '= S (first L)) (second L))))

(def groupAll
  (fn [S L]
    (if (not(empty? L))
      (concat (groupUp S L) (groupAll S (rest (rest L)))))))



(defmacro which
  [S & L]
  (let [stuff (groupAll S L)]
  `(cond ~@stuff)))




;-------------------------------------------------------------------------------
; macro: comps
; A macro of the that does performs a 1-ary function on const k,
; In: 1-ary function f, nonnegative integer constant k
; Out: expansion of comps
;-------------------------------------------------------------------------------
;(defmacro comps [f k]


(def compsHelp
  (fn [f k]
    (let [g f]
      (if (> k 0)
        (do
          (g))))))



;-------------------------------------------------------------------------------
; macro: qrat
; A macro of the quadratic formula
; In: + or -, parts a, b, and c
; Out: list with answer
;-------------------------------------------------------------------------------
(defmacro qrat
  [op a b c]
    `(/ (~op (- ~b) (Math/sqrt (- (* ~b ~b) (* 4.0 ~a ~c)))) (* 2.0 ~a)))

; testing for most
;(macroexpand-1 '(most true false false))
;(most true false false true true)

; test cases for which
;(macroexpand-1 '(which 3 2 (println "2") 3 (println "3")))
;(which 3 2 (* 2 3) 3 (* 3 3))
	
; test case for qrat
;(println (qrat + 1.0 8.0 (- 10.0)))
;(println (qrat - 1.0 8.0 (- 10.0)))
