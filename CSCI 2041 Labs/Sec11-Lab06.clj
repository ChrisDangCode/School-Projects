;===============================================================================
; Assignment: Lab 6
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Oct. 18, 2016
;===============================================================================

;-------------------------------------------------------------------------------
; moreUnique 
; In: function for continuation, a seq or list 
; Out: nil or whatever f does to the first of the set
;-------------------------------------------------------------------------------
(def moreUnique
  (fn [f s]
    (if (some (fn [st] (= (first s) st)) (rest s))
    nil
    (f (first s)))))


;-------------------------------------------------------------------------------
; unique 
; In: function for continuation, a seq or list 
; Out: nil or whatever f does to the set
;-------------------------------------------------------------------------------
(def unique
  (fn [f s]
  
    (if (empty? s)
    nil
    (let [stuff (moreUnique f s)]
    (unique f (rest s))))))


; Test case
;(unique println '(a b a c b c c a b))






(def mapper
  (fn [f l]           ; f is a function, l is a list
    (if (empty? l)
      '()
      (cons (f (first l))
        (mapper f (rest l))))))


; test
;(println(mapper (fn [s] (/ s 2)) '(1 4 6 8 10 12 14)))



(def pair
  (fn [s1 s2]
    (if (empty? s2)
      '()
    (cons (list (first s1) (first s2)) (pair s1 (rest s2))))))
        
        
        
(def pairAll
  (fn [s1 s2]
  ;(println "s1 is:" s1 "s2 is:" s2)
    (if (not(empty? s1))
      (let [s (pair s1 s2)]
      (concat s (pairAll (rest s1) s2))))))
      


(def cartesian
  (fn [op s1 s2]
    (mapper (fn [ops] ops) (pairAll s1 s2))))
    
;(println (mapper / '(2 3) ))

;(println (pairAll '(1 2 3) '(4 5)))
;(println (pairAll '(a b c) '(d e)))
(cartesian / '(2 3) '(5 7))

(println (pairAll '(2 3) '(5 7)))




(def nest
  (fn [F N]
      (fn []
        (if (not= N 0)
          (nest F (N - 1))))))

(def inc0 (nest 'inc 0))
; test case
;(println (inc0 1))
