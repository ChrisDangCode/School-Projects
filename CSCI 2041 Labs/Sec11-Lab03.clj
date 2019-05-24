;===============================================================================
; Assignment: Lab 3
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Sept. 27, 2016
;===============================================================================
(declare splitting merging mergesort)

;-------------------------------------------------------------------------------
; splitting: splits items and sorts between left and right side
; In: less than operater, unsorted list, and 2 lists
; Out: sorted list
;-------------------------------------------------------------------------------
(def splitting
	(fn [less? unsorted left right]
      ; case: unsorted has 2 or more items
    (cond (>= (count unsorted) 2)
      (splitting less? (rest (rest unsorted)) ; unsorted has first 2 items removed
      (cons (first unsorted) left)        ; Append first of unsorted to left
      (cons (second unsorted) right))     ; Append second of unsorted to right
      ; case: unsorted has 1 item
    (== (count unsorted) 1)
      (merging less? (mergesort less? (cons (first unsorted) left)) (mergesort less? right))
    :else
    (if (empty? unsorted)
      (merging less? (mergesort less? left) (mergesort less? right))))))
      
      
      
;-------------------------------------------------------------------------------
; merging: merges elements together
; In: less than operater, 2 lists
; Out: merged list
;-------------------------------------------------------------------------------
(def merging
  (fn [less? left right]
        (cond (empty? left)
            right        ; if one side of list is empty, return non empty side of list
          (empty? right)
            left
        ; neither side is empty at this point
        (less? (first left) (first right))
          (cons  (first left) (merging less? (rest left) right))
        :else
          (cons (first right) (merging less? left (rest right))))))



;-------------------------------------------------------------------------------
; mergesort: takes a list and sorts elements using mergesort
; In: less than operater and list
; Out: sorted list
;-------------------------------------------------------------------------------
(def mergesort
	(fn [less? unsorted]
    (if (<= (count unsorted) 1)
    unsorted
		(splitting less? unsorted '() '() ))))




; Test cases
;(println "case: 0 elements:"(mergesort < '()))
;(println "case: 1 elements:"(mergesort < '(9)))
;(println "case: n elements:"(mergesort < '(9 8)))
;(println "case: n elements:"(mergesort < '(9 8 7 6 5 4 3 2 1)))
;(println "case: n elements:"(mergesort < '(10 6 4 8 2 7 5)))
;(println "case: n elements:"(mergesort < '(1 2 3 4 5 6 7 8 9)))
