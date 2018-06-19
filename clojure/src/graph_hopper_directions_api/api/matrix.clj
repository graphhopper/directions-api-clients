(ns graph-hopper-directions-api.api.matrix
  (:require [graph-hopper-directions-api.core :refer [call-api check-required-params with-collection-format]])
  (:import (java.io File)))

(defn matrix-get-with-http-info
  "Matrix API
  The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times.
In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this."
  ([key ] (matrix-get-with-http-info key nil))
  ([key {:keys [point from-point to-point out-array point-hint to-point-hint from-point-hint vehicle ]}]
   (check-required-params key)
   (call-api "/matrix" :get
             {:path-params   {}
              :header-params {}
              :query-params  {"point" (with-collection-format point :multi) "from_point" (with-collection-format from-point :multi) "to_point" (with-collection-format to-point :multi) "out_array" (with-collection-format out-array :multi) "point_hint" (with-collection-format point-hint :multi) "to_point_hint" (with-collection-format to-point-hint :multi) "from_point_hint" (with-collection-format from-point-hint :multi) "vehicle" vehicle "key" key }
              :form-params   {}
              :content-types []
              :accepts       ["application/json"]
              :auth-names    []})))

(defn matrix-get
  "Matrix API
  The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times.
In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this."
  ([key ] (matrix-get key nil))
  ([key optional-params]
   (:data (matrix-get-with-http-info key optional-params))))

(defn matrix-post-with-http-info
  "Matrix API Post
  The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request."
  ([key ] (matrix-post-with-http-info key nil))
  ([key {:keys [body ]}]
   (check-required-params key)
   (call-api "/matrix" :post
             {:path-params   {}
              :header-params {}
              :query-params  {"key" key }
              :form-params   {}
              :body-param    body
              :content-types []
              :accepts       ["application/json"]
              :auth-names    []})))

(defn matrix-post
  "Matrix API Post
  The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request."
  ([key ] (matrix-post key nil))
  ([key optional-params]
   (:data (matrix-post-with-http-info key optional-params))))

