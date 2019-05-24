;=======================================================================
; Lab 2
; CSCI 2041-011 Advanced Programming
; Chris Dang
;=======================================================================

;-----------------------------------------------------------------------
; Matching: Function recieves a pattern, subject from Match, and an
; empty hash table.
;-----------------------------------------------------------------------
(def matching
  (fn [pattern subject table]
    (if (keyword? pattern)                 ; case 1: if pattern is keyword
        (if (not= (get table pattern) nil)      ; code written with assistence from TA Isaac
          (if (= (get table pattern) subject)
            table
            nil)
          (assoc table pattern subject))
          
      
                   
      (if (and (seq? pattern) (seq? subject) (not (empty? pattern)) (not (empty? subject))) ; case 2: pattern and subject are non-empty seqs
        (let [storP (matching (first pattern) (first subject) table)]
          (if (= storP nil)
          nil
          (recur (rest pattern) (rest subject) storP)))
        
        (if (= pattern subject)               ; case 3: neither case 1 or 2.
          table
          nil)))))

;-----------------------------------------------------------------------
; Match: Function matches patterns to subjects
; In: Pattern and subject
; Out: Nil, empty set, or map
;-----------------------------------------------------------------------
(def match
  (fn [pattern subject]
      (matching pattern subject (hash-map))))
    


; Test cases
(comment
(println "                            (match '() '()) ==> " (match '() '() ))
(println "                       (match '() '(1 2 3)) ==> " (match '() '(1 2 3)))
(println "                 ((match '(1 2 3) '(1 2 3)) ==> " (match '(1 2 3) '(1 2 3)))
(println "              (match '(1 (2 3)) '(1 (2 3))) ==> " (match '(1 (2 3)) '(1 (2 3))))
(println "                    (match '(1 2) '(1 (2))) ==> " (match '(1 2) '(1 (2))))
(println "table cases")
(println "       (match '(:a is a :b) '(this is a 1)) ==> " (match '(:a is a :b) '("1" is a "2")))
(println "(match '(:a is a :b) '(this is a (hard 1))) ==> " (match '(:a is a :b) '(this is a (hard 1))))
(println "(match '(:a is :b) '((a rose) is (a rose))) ==> " (match '(:a is :b) '((a rose) is (a rose))))
(println "(match '(:a is :a) '((a rose) is (a rose))) ==> " (match '(:a is :a) '((a rose) is (a rose))))

(println "nil cases")
(println "                          (match '(:a) '()) ==> " (match '(:a) '()))
(println "(match '(:a is a :b) '(this is not a test)) ==> " (match '(:a is a :b) '(this is not a test)))
(println (match '(:a) '(test)))
)
