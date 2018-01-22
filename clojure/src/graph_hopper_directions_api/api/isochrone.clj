(ns graph-hopper-directions-api.api.isochrone
  (:require [graph-hopper-directions-api.core :refer [call-api check-required-params with-collection-format]])
  (:import (java.io File)))

(defn isochrone-get-with-http-info
  "Isochrone Request
  The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate
'a line connecting points at which a vehicle arrives at the same time,'
see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map).
It is also called **reachability** or **walkability**."
  ([point key ] (isochrone-get-with-http-info point key nil))
  ([point key {:keys [time-limit distance-limit vehicle buckets reverse-flow ]}]
   (check-required-params point key)
   (call-api "/isochrone" :get
             {:path-params   {}
              :header-params {}
              :query-params  {"point" point "time_limit" time-limit "distance_limit" distance-limit "vehicle" vehicle "buckets" buckets "reverse_flow" reverse-flow "key" key }
              :form-params   {}
              :content-types []
              :accepts       ["application/json"]
              :auth-names    []})))

(defn isochrone-get
  "Isochrone Request
  The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate
'a line connecting points at which a vehicle arrives at the same time,'
see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map).
It is also called **reachability** or **walkability**."
  ([point key ] (isochrone-get point key nil))
  ([point key optional-params]
   (:data (isochrone-get-with-http-info point key optional-params))))

