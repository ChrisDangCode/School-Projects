;===============================================================================
; Assignment: Lab 10
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Nov. 30, 2016
;===============================================================================




(def partial-ordering
  (hash-map
    'A  #{'C}
    'B  #{'H}
    'C  #{'G}
    'G  #{'D 'E}
    'D  #{'F}
    'E  #{'H}
    'H  #{'F}
    'I  #{'B 'E}))















(def unpreceded
  (fn [etc precedes? objects]
    (loop )))





(def unpreceded?
  (fn [precedes? object other-objects]
    (not (some (fn [item] (precedes? item object)) other-objects))))






(def delete
  (fn [objects object]
    (remove (partial = object) objects)))



(def precedes?
  (fn [left right]
    (contains? (get partial-ordering left) right)))



;(some (precedes? 'A (get '(A B C G) 2)) '(A B C G))
