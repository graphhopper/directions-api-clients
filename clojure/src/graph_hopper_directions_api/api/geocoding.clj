(ns graph-hopper-directions-api.api.geocoding
  (:require [graph-hopper-directions-api.core :refer [call-api check-required-params with-collection-format]])
  (:import (java.io File)))

(defn geocode-get-with-http-info
  "Execute a Geocoding request
  This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/"
  ([key ] (geocode-get-with-http-info key nil))
  ([key {:keys [q locale limit reverse point provider ]}]
   (check-required-params key)
   (call-api "/geocode" :get
             {:path-params   {}
              :header-params {}
              :query-params  {"q" q "locale" locale "limit" limit "reverse" reverse "point" point "provider" provider "key" key }
              :form-params   {}
              :content-types []
              :accepts       ["application/json"]
              :auth-names    []})))

(defn geocode-get
  "Execute a Geocoding request
  This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/"
  ([key ] (geocode-get key nil))
  ([key optional-params]
   (:data (geocode-get-with-http-info key optional-params))))

