;; Anything you type in here will be executed
;; immediately with the results shown on the
;; right.



(def evaluate-fn
 (fn [form scope]
  (atom 'closure
   (second form)
   (first (rest (rest form)))
   scope)))


(def example '(let [x 1]))
(def scope 5)


(evaluate-fn example)

;(deref (atom 'closure (second example) (first (rest (rest example))) scope))