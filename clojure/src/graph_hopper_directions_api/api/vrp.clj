(ns graph-hopper-directions-api.api.vrp
  (:require [graph-hopper-directions-api.core :refer [call-api check-required-params with-collection-format]])
  (:import (java.io File)))

(defn post-vrp-with-http-info
  "Solves vehicle routing problems
  This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution."
  [key request ]
  (check-required-params key request)
  (call-api "/vrp/optimize" :post
            {:path-params   {}
             :header-params {}
             :query-params  {"key" key }
             :form-params   {}
             :body-param    request
             :content-types ["application/json"]
             :accepts       ["application/json"]
             :auth-names    []}))

(defn post-vrp
  "Solves vehicle routing problems
  This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution."
  [key request ]
  (:data (post-vrp-with-http-info key request)))

