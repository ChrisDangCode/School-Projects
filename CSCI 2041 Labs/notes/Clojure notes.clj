
;11-23-2016 Clojure lecture

; Atoms. Similar to local variables in nonfunctioanal languages
; Search based programming:
;   Graph searches (traverals)
;   DFS, BFS

;Note: Bug in prgramming project 2, has been fixed.


; Atom - data object that acts like a variable. Scheme and common lisp have a similar object,
; BUT they are totally different.

(def a 4)
(def v 5)

(atom v) ; returns an atom with initial val v.

(deref (atom a)) ; gets the value of the atom immediately, without blocking

(swap! (atom a) seq?) ; calls f on the current value of a. Replaces the value of a with what the function returns.
; f is a 1 array function.

; atomic transaction of atomic update, an action that can't be interrupted


; swap works like this:
; (compare and set)

; 1. Reads current value of a, it's v.
; 2. Call (f v).
; 3. Is v stil equal to the current value of a?
; 4. Yes: update a to have (f v) as its value, and STOP.
; 5. No: got to 1.


(reset! (atom a) 10) ; ==== equiv to (swap a (fn [x] v))
; reset! is kind of like assigment operator.



(def at (atom 0))
(deref at) ; => 0
(reset! at 1) ; => 1
(def b at)
(reset! b 2)
(deref at) ; => 2      >:(














; Graph info: (not clojure code)
; G = <V, E>
; V = {v_1, v_2, ... , v_n} (vertices, NOT Vertisee. Moen is peeved at vertisee)
; E in the set V x V  {(v_1, v_2) (v_2, v_3) (v_3, v_4) ...}


;; Light table notes: use "ctrl + ." to comment a line


;; Graph traversal:
;; 1: start at a vertex
;; 2: visit each vertex accessible from there
;; 3: visit each vertex 1 time.
;; 4: avoid being trapped in cycle(s).


;; visit: 1-ary function, graph: pointer to li
;; #{} is a set


(def  neighbors
  (fn [function graph vertex]
    (loop [vertexes (get graph vertex)]
      (if (not (empty? vertexes))
        (do
          (function (first vertexes))
          (recur (rest vertexes)))))))

(def depth-firsting
  (fn [visit graph vertex visited]
    (if (not (contains? (deref visited) vertex))
      (do
        (reset! visited (conj (deref visited) vertex)) ; mark this noted as visited
        (visit vertex)
        (neighbors
          (fn [other_vertex]
            (depth-firsting visit graph other_vertex visited))
          graph vertex)))))

(def depth-first
  (fn [visit graph vertex]
    (depth-firsting visit graph vertex (atom #{}))))







(def make-queue
  (fn []
    '()))

;; (def enqueues
;;   (fn [queue vertexes]
;;     (concat queue vertexes)))


;; (def dequeue
;;   (fn [queue]
;;     (rest queue)))

;; (def queue-empty?
;;   (fn [queue]
;;     (empty? queue)))

;; (def front
;;   (fn [queue]
;;     (first queue)))

(def enqueues concat)
(def dequeue rest)
(def front first)
(def queue-empty? empty?)












(def breadth-firsting
  (fn [visit graph queue visited]
    (if (not (queue-empty? queue))
      (let [vertex (front queue)]
        (if (contains? (deref visited) vertex)
          (recur visit graph (dequeue queue) visited)
          (do
            (reset! visited (conj (deref visited) vertex))
            (visit vertex)
            (recur visit graph (enqueues (dequeue queue) (get graph vertex))
                   visited)))))))

(def breadth-first
  (fn [visit graph vertex]
    (let [visited (atom #{})]
      (breadth-firsting visit graph (enqueues (make-queue) (list vertex)) visited
                       (deref visited)))))




; 11-30-2016
; Type systems
;   When are 2 types camptible?
;   What does it mean  for 2 types to be compatible?
;   How to describe a type system?
;   How to implement a type system?


; Barbara Liskov (MIT, 1939 - _)
; Liskov's Law (substitution principle)

; 1. Place in a program where an object of t_1 is expected.
; a + b
; 2. In that place, ob object of t_2 can be provided.
; 3. Then we say t_2 is a subtype of t_1.
; t_2 is a subset of t_1


; type is a set of objects
; bool is a subset of int, which is a subset of real val, which is a subset of a complex value.


; What's a type?
; - Tells you a representation.
; - Tells you operations.
; - Tells you what's legal - detect errors.


; Name compatibility: 2 types are the same (subtypes?) if they have the same name.

; Structure compatibility.
;   Compare corresponding parts of two types. All comparisons sourced, the types are the same.

; Pascal (N. Wirth)
;





















; Luca Cardelli - wrote a paper called "Type Systems"

(def make-inc
  (fn [k]
    (fn [n]
      (+ n k))))



(def simple-type? symbol?
  (fn [left right]
    (and
      (simple-type? right)
      (constains? (get simple-subtypes left) right))))



(def simple-subtypes
  (hash-map
    'bool #{'int 'real 'complex}
    'int #{'real 'complex}
    'real #{'complex}
    'complex #{}))


(def array-length
  (fn [form]
    (second (rest form))))

(def array-base second)


(def array-type?
  (fn [type]
    (and
      (not (empty? type))
      (= (first type) 'array))))

(def array-subtype?
  (fn [left right]
    (and (array-type? right)
         (== (array-length left) (array-length right))
         (subtype?
           (array-base right)))))



; rules from tower of rules
(def subtype?
  (fn [left right]
    (cond
      (= left right)   ; rule 0.
      true
      (simple-type? left)
      (simple-subtype? left right)

      (array-type? left)
      (array-subtype? left right)

      (proc-type? left)
      (proc-subtype? left right)

      true
      (error "not a type."))))



; rule 4
(def proc-subtype?
  (fn [left right]
    (and
      (proc-type? right)
      (subtype?
        (proc-result left)
        (proc-result right))
      (all
        (fn [right-param left-param]
          (subtype? right-param left-param))
        (proc-parameters right)
        (proc-parameters left)))))


; rule 5 from tower of rules
(def all
  (fn [pred lefts rights]
    (if
      (or
        (empty? lefts)
        (empty? rights))
      (and
        (empty? lefts)
        (empty? rights))
      (and
        (pred (first lefts) (first rights))
        (recur pred (rest lefts) (rest rights))))))













;(pro '(t_1, t_2 ... t_k) t)
;(proc-parameters '(proc(t_1, t_2 ... t_k))) => '(t_1, t_2 ... t_k)
;(proc_result '(proc (...) t )) => t



; 2016_12_14
; LAST CLOJURE LECTURE


; Topics:
  ; Functional programming in Java >:(



; "All languages secretely want to become lisp." - Joke among people interested in computer langauges.


; forAll(M, a), where a is an array, M is method; THis calls M on each element.

(def forAll
  (fn [f v]
    (loop [i 0]
      (if
        (< i (count v))
        (do
          (f (get v i))
          (recur (+ i 1)))))))

(forAll println v)



; Reflection - Data objects that represent parts of the language.

; java.lang.reflect
  ; Class
  ; Method

  ; Classical (1990's) Java

  ; Anonymous function - Lambda
  ; Alonzo Church - Lambda Calc.
    ; (fn [p_1 p_2 ... p_n] e) == (lambda (p_1 p_2 ... p_k) e)


  class lambda {
                 public void method (int number)
                 {
                   System.out.println(number);
                   }
                 }

class lambdademo
{ public void forAll(lambda lambda, int [] array)
  {
    for (int index = 0 , index < array.length , index += 1){
             lambda.method(array[index])
             }
            }
          }

class printElements{
                     public static void main (
                                               string [] args)
                     {in [] array = new int [10];
                      lambdademo demo = new lambdademo()}
                     demo.forAll(new lambda(), array) ;
                     }


; Java 8
; Lambda expressions
; (t_1 p_1, t_2 p_2 ... t_n p_n) -> e
; where t is a type, and p is a parameter name

; (int n) -> n + 1
; (int n) -> {system.out.println(n);}


class printElements{
public static void main(string [] args)
                     {
                       int [] array = new int[10];
                       ...
                       lambdademo demo = new lambdademo();
                       demo.forall((int k) -> {system.out.println(k);} array);
                       }
                     }

















































