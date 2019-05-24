;===============================================================================
; Assignment: Lab 10
; Class: CSCI 2041-011 Advanced Programming
; Name: Chris Dang
; Created: Nov. 17, 2016
;===============================================================================


; ERROR. Throw an exception that represents an error.
; From stack implementation on Moodle
(def error
 (fn [message]
  (throw (Exception. message))))


(def queue
  (fn []
    (letfn

      [(make-queue [front]
        (fn [method & args]
          (letfn
          
          
          ; EMPTY?
          [(emptyQ? []
            (= front '()))
            
          ; ENQUEUE
          (enqueue [item]
            (make-queue (cons item front)))
            
          ; DEQUEUE
          (dequeue []
            (if (emptyQ?)
              (error "Queue is empty.")
              (make-queue (rest front))))
          
          ; FRONT
          (front []
            (if (emptyQ?)
              (error "Queue is empty.")
              (first front)))]
          
          
          (cond
            (= method :emptyQ?)
            (emptyQ?)
            
            (= method :enqueue)
            (enqueue [first args])
            
            (= method :dequeue)
            (dequeue)
            
            (= method :front)
            (front)
            
            true
            (error "No such method")))))]
      
      
      
      
      (make-queue '()))))
      


(def q0 (queue))         ;  Q0 is a new empty stack.
(println (q0 :emptyQ?))   ;  true

(def q1 (q0 :enqueue "A"))  ;  S1 is S0 but with "A" pushed on it.
(println (q1 :emptyQ?))   ;  false
(println (q1 :front))     ;  A

(def q2 (q1 :enqueue "B"))  ;  S2 is S1 but with "B" pushed on it.
(println (q2 :emptyQ?))   ;  false
(println (q2 :front))     ;  B

(def q3 (q2 :dequeue))       ;  This gets us a stack like S1 again.
(println (q3 :emptyQ?))   ;  false
(println (q3 :front))     ;  A

(q3 :nope)             ;  No such method as :nope so we get an error.
      
      
      
      
      
      
      
      
      
      
