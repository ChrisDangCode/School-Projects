;===============================================================================
; Assignment: Lab 4
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Oct. 4, 2016
;===============================================================================

;-------------------------------------------------------------------------------
; operater - getter function for prefixed items
; In: A set of items
; Out: The operat in a prefixed statement
;-------------------------------------------------------------------------------
(def operater
	(fn [items]
	(first items)))


;-------------------------------------------------------------------------------
; left-arg - getter function for prefixed items
; In: A set of items
; Out: The first of 2 arguments in a prefixed statement
;-------------------------------------------------------------------------------
(def left-arg
	(fn [items]
	(second items)))


;-------------------------------------------------------------------------------
; right-arg - getter function for prefixed items
; In: A set of items
; Out: The second of 2 arguments in a prefixed statement
;-------------------------------------------------------------------------------
(def right-arg
	(fn [items]
	(second (rest items))))
  
  
;-------------------------------------------------------------------------------
; convert - converter from math symbol to english operation
; In: operator
; Out: set containing the operation in english
;-------------------------------------------------------------------------------
(def convert
  (fn [op]
    (cond
    (= '("push" *) op)
    '("mul")
    
    (= '("push" /) op)
    '("div")
    
    (= '("push" +) op)
    '("add")
    
    (= '("push" -) op)
    '("sub")
    :else
    op )))






;-------------------------------------------------------------------------------
; addPop - adds the 'pop' instruction to the end of stack instructions
; In: nothing
; Out: The set containing string "pop"
;-------------------------------------------------------------------------------
(def addPop
  (fn []
		'("pop")))
    
    
    
;-------------------------------------------------------------------------------
; stacking - Helper function for stackify, illutrates all push and math operators
; In: prefixed math operations
; Out: The set containing commands to the stack
;-------------------------------------------------------------------------------
(def stacking
	(fn [item]
		(cond 
    
		(not= (seq? item) true) ; case 1: item is just a number
		(list (convert(cons "push" (cons item '()))))
    
    (= (count item) 2)    ; case 2: item is to be negated
    (concat (stacking (left-arg item)))
    
    (= (count item) 3)    ; case 3: recursive case
    (concat (stacking (left-arg item)) (stacking (right-arg item)) (stacking (operater item))))))
  
;-------------------------------------------------------------------------------
; stackify - simulate pushing prefixed math operations to stack
; In: prefixed math operations
; Out: The set containing commands to the stack with final pop
;-------------------------------------------------------------------------------
(def stackify
  (fn [item]
    (concat (stacking item) (list(addPop)))))




(comment
; Test cases:
(println (convert '(*)))

(println (cons '("stuff") '() ))
(println (addPop))
  
(println(operater '(* u v)))
(println(left-arg '(* u v)))
(println(right-arg '(* u v)))

(println (stackify -1))
(println (stackify '(- 1)))


(println (stackify '(* u v)))
(println (stackify '(- (* u v) w)))
(println (stackify '(+ ( / (- (* u v) w) t) g)))
)
