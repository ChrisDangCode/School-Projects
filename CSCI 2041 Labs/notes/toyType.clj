;
;  TOYTYPE. A toy type system.
;
;    James Moen
;    02 Dec 16
;
;  This is the toy type system from the lectures, with a few changes. The ARRAY
;  type is missing, because we won't need it for Project 3.  A new type OBJ has
;  also been added; all types are subtypes of OBJ.
;

;  Yadda yadda yadda, so we can define things in a readable order.

(def error)
(def pairwise)
(def proc-parameters)
(def proc-result)
(def proc-subtype?)
(def proc-type?)
(def simple-subtype?)
(def simple-type?)
(def subtype?)

;  SIMPLE-SUBTYPES. Assert that simple subtypes are subtypes of each other.
;
;    t ⊆ complex   t ⊆ real   t ⊆ int
;    ───────────   ────────   ────────
;     t ⊆ real     t ⊆ int    t ⊆ bool

(def simple-subtypes
 (hash-map
   'bool  #{'int 'real 'complex}
   'int   #{'real 'complex}
   'real  #{'complex}))

;  SUBTYPE?. Test if LEFT-TYPE is a subtype of RIGHT-TYPE.
;
;     t ⊆ t     t ⊆ obj
;    ───────    ───────    
;     true       true

(def subtype?
 (fn [left-type right-type]
  (cond
   (= left-type right-type)
   true

   (= right-type 'obj)
   true

   (simple-type? left-type)
   (simple-subtype? left-type right-type)

   (proc-type? left-type)
   (proc-subtype? left-type right-type)

   true
   (error "Type expected."))))

;  SIMPLE-TYPE?. Test if an object is a simple type.

(def simple-type? symbol?)

;  SIMPLE-SUBTYPE?. Test if simple type LEFT-TYPE is a subtype of RIGHT-TYPE.

(def simple-subtype?
 (fn [left-type right-type]
  (and
   (simple-type? right-type)
   (contains? (get simple-subtypes left-type) right-type))))

;  LIST-TYPE?. Test if TYPE is a list type.

(def list-type?
 (fn [type]
  (and
   (not (empty? type))
   (= (first type) 'list))))

;  PROC-TYPE?. Test if TYPE is a PROCedure type.

(def proc-type?
 (fn [type]
  (and
   (not (empty? type))
   (= (first type) 'proc))))

;  PROC-SUBTYPE?. Test if PROCedure type LEFT-TYPE is a subtype of RIGHT-TYPE.
;
;    proc (t₁ t₂ ... tⱼ) t ⊆ proc (T₁, T₂ ..., Tⱼ) T
;    ───────────────────────────────────────────────
;       T₁ ⊆ t₁,  T₂ ⊆ t₂  ...,  Tⱼ ⊆ tⱼ,  t ⊆ T

(def proc-subtype?
 (fn [left-type right-type]
  (and
   (proc-type? right-type)
   (subtype?
    (proc-result left-type)
    (proc-result right-type))
   (pairwise
    (fn [left-parameter right-parameter]
     (subtype? right-parameter left-parameter))
    (proc-parameters left-type)
    (proc-parameters right-type)))))

;  PROC-RESULT. Return the result type of a PROCedure type.

(def proc-result (comp first rest rest))

;  PROC-PARAMETERS. Return the list of parameter types from a PROCedure type.

(def proc-parameters (comp first rest))

;  PAIRWISE. Test if each element of LEFTS, and each positionally corresponding
;  element of RIGHTS, satisfies the 2-ary predicate TEST?.

(def pairwise
 (fn [test? lefts rights]
  (if
   (or
    (empty? lefts)
    (empty? rights))
   (and
    (empty? lefts)
    (empty? rights))
   (and
    (test?
     (first lefts)
     (first rights))
    (recur test?
     (rest lefts)
     (rest rights))))))

;  ERROR. Assert that an error has occurred.

(def error
 (fn [message]
  (throw (Exception. message))))
