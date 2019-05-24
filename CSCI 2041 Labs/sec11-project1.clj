;===============================================================================
; sec11-project1.clj
; Project 1
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Oct. 25, 2016
;===============================================================================

;-------------------------------------------------------------------------------
; Function: op, left, right, make-if, if-test, if-then, if-else
; Grab item corresponding to title of function from logical statement
;-------------------------------------------------------------------------------
(def op
  (fn [l]
    (first l)))
    
(def left
  (fn [l]
    (second l)))

(def right
  (fn [l]
    (second (rest l))))

(def make-if
  (fn [a b c]
    (list 'if a b c)))

(def if?
  (fn [l]
    (if (seq? l)
      (if (= (first l) 'if)
        true
        false)
      false)))

(def if-test
  (fn [l]
    (second l)))
    
(def if-then
  (fn [l]
    (second (rest l))))
    
(def if-else
  (fn [l]
    (second (rest (rest l)))))
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; Function: ifify
; Convert logical statement to if's
;-------------------------------------------------------------------------------
(def ifify
  (fn [p]
    (if (seq? p)
      (cond
        (= (op p) 'not) ; rule 1
          (make-if (ifify (left p)) 'false 'true)
        
        (= (op p) 'and) ; rule 2
          (make-if (ifify (left p)) (ifify (right p)) 'false)
        
        (= (op p) 'or) ; rule 3
          (make-if (ifify (left p)) 'true (ifify (right p)))
        
        (= (op p) 'imply) ; rule 4
          (make-if (ifify(left p)) (ifify(right p)) 'true)
        
        (= (op p) 'equiv) ; rule 5
          (make-if (ifify(left p)) (ifify(right p)) (make-if (ifify(right p)) 'false 'true))
        
        :else
          p) ; return p for cond
        
      p))) ; return p for if



;-------------------------------------------------------------------------------
; Function: normalize
; Convert nested if's to have only boolean expression
;-------------------------------------------------------------------------------
(def normalize
  (fn [s]
    (if (seq? s)
      (loop [a (if-test s) b (if-then s) c (if-else s)]
        (if (if? a)
          (recur (if-test a) (make-if (if-then a) b c) (make-if (if-else a) b c))
        (make-if a (normalize b) (normalize c))))
      s)))
        
;-------------------------------------------------------------------------------
; Function: substitute
; Substitute values of v with b in the experession c
;-------------------------------------------------------------------------------
(def substitute     ; rule 6
  (fn [c v b]
    (if (if? c)
      (if (= (if-test c) v)
        (make-if b (substitute (if-then c) v b) (substitute (if-else c) v b))
        (make-if (substitute(if-test c) v b) (substitute (if-then c) v b) (substitute (if-else c) v b)))
      (if (= c v)
      b
      c))))
  
;-------------------------------------------------------------------------------
; Function: simplify
; convert expressions for final evaluation of the tautology
;-------------------------------------------------------------------------------
(def simplify
  (fn [s]
    (if (if? s)
      (cond
        (= (if-test s) 'true)         ; rule 7
          (simplify (if-then s))
        
        (= (if-test s) 'false)        ; rule 8
          (simplify (if-else s))
          
          :else
          
            (let [newThen (simplify(substitute (if-then s) (if-test s) 'true))
            newElse (simplify(substitute (if-else s) (if-test s) 'false))]
              
              (cond
            
              (and (= newThen 'true) (= newElse 'false)) ; rule 9
                (if-test s)
              
              (= newThen newElse)   ; rule 10
                newThen
              
            :else
              (make-if (if-test s) newThen newElse))))  ; rule 11
            s)))

;-------------------------------------------------------------------------------
; Function: tautology
; Determine if statement is a tautology
;-------------------------------------------------------------------------------
(def tautology
  (fn [e]
    (= (simplify (normalize (ifify e))) 'true)))


; test case      
;(println (ifify '(imply  (not (and p q)) (or (not p) (not q)))))
;(println (normalize '(if (if pi a1 b1) a2 b2)))
;(println (simplify (normalize(ifify '(imply  (not (and p q)) (or (not p) (not q)))))))
;(println (tautology '(imply  (not (and p q)) (or (not p) (not q)))))



