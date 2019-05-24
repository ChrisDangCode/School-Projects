;  ERROR. Throw an exception that represents an error.

(def error
 (fn [message]
  (throw (Exception. message))))

;  STACK. An OOP stack implemented with function closures.

(def QNOW
 (fn []
  (letfn

;  MAKE-STACK. Return a closure that represents a stack. It uses a list TOP.

   [(make-Q [front]
     (fn [method & arguments]
      (letfn

;  EMPTY? Test if the stack is empty.

       [(empty? []
         (= front '()))

;  PUSH. Return a new stack like this one but with OBJECT pushed on top of it.

        (enqueue [object]
         (make-Q (cons object front)))

;  POP. Return a new stack like this one but without its top object.

        (dequeue []
         (if
          (empty?)
          (error "Stack is empty.")
          (make-Q (rest front))))

;  PEEK. Return the object on top of this stack.

        (front []
         (if
          (empty?)
          (error "Stack is empty.")
          (first front)))]

;  This is the body of the inner LETFN. Dispatch on METHOD to a function call.

       (cond
        (= method :empty?)
        (empty?)

        (= method :enqueue)
        (enqueue (first arguments))

        (= method :dequeue)
        (dequeue)

        (= method :front)
        (front)

        true
        (error "No such method.")))))]

;  This is the body of the outer LETFN. We return a new empty stack.

   (make-Q '()))))

;  Some test code. The comments show what will be printed.

(def s0 (QNOW))         ;  S0 is a new empty stack.
(println (s0 :empty?))   ;  true

(def s1 (s0 :enqueue "A"))  ;  S1 is S0 but with "A" pushed on it.
(println (s1 :empty?))   ;  false
(println (s1 :front))     ;  A

(def s2 (s1 :enqueue "B"))  ;  S2 is S1 but with "B" pushed on it.
(println (s2 :empty?))   ;  false
(println (s2 :peek))     ;  B

(def s3 (s2 :dequeue))       ;  This gets us a stack like S1 again.
(println (s3 :empty?))   ;  false
(println (s3 :front))     ;  A

(s3 :blooey)             ;  No such method as :BLOOEY so we get an error.
