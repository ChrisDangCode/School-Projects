;=======================================================================
; TESTING FILE
; CSCI 2041-011 Advanced Programming
; Chris Dang
;=======================================================================

;(println((and + -) 1 2 3)) ; => -4

;((fn [x]
  ;(println "hello" x)) "Tony Stark")


;((fn [x]
  ;(println (conj (list (+ 1 2)) x))
  ;(println "You're out!")) "I did stuff!")


;(println (#(* % 3) 10)) ; => 30       % == % 1, where '%' is the arg


;(def dalmatian-list
  ;["Pongo" "Perdita" "Puppy 1" "Puppy 2"])

;(println (let [dalmatians (second dalmatian-list)]
  ;dalmatians))


(def scope 5)
(println "scope first is:" scope)
(let [scope (atom scope)]
  (println "scope now is:" scope)
  (println "scope contains" (deref scope)))





(letfn [(triple [x]
          (* x 3))] 
          
          (println (triple 2)))
        

(def get_i
  (fn [L I]
    (loop [f 10]
      (println f)
      (if (= I 0)
        (first L)
        (get_i (rest L) (- I 1))))))

(println (get_i '(1 2 3 4 5) 2))
