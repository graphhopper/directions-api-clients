(ns graph-hopper-directions-api.api.routing
  (:require [graph-hopper-directions-api.core :refer [call-api check-required-params with-collection-format]])
  (:import (java.io File)))

(defn route-get-with-http-info
  "Routing Request
  The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions"
  ([point points-encoded key ] (route-get-with-http-info point points-encoded key nil))
  ([point points-encoded key {:keys [locale instructions vehicle elevation calc-points point-hint chdisable weighting edge-traversal algorithm heading heading-penalty pass-through round-tripdistance round-tripseed alternative-routemax-paths alternative-routemax-weight-factor alternative-routemax-share-factor ]}]
   (call-api "/route" :get
             {:path-params   {}
              :header-params {}
              :query-params  {"point" (with-collection-format point :multi) "locale" locale "instructions" instructions "vehicle" vehicle "elevation" elevation "points_encoded" points-encoded "calc_points" calc-points "point_hint" (with-collection-format point-hint :multi) "ch.disable" chdisable "weighting" weighting "edge_traversal" edge-traversal "algorithm" algorithm "heading" heading "heading_penalty" heading-penalty "pass_through" pass-through "round_trip.distance" round-tripdistance "round_trip.seed" round-tripseed "alternative_route.max_paths" alternative-routemax-paths "alternative_route.max_weight_factor" alternative-routemax-weight-factor "alternative_route.max_share_factor" alternative-routemax-share-factor "key" key }
              :form-params   {}
              :content-types []
              :accepts       ["application/json"]
              :auth-names    []})))

(defn route-get
  "Routing Request
  The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions"
  ([point points-encoded key ] (route-get point points-encoded key nil))
  ([point points-encoded key optional-params]
   (:data (route-get-with-http-info point points-encoded key optional-params))))

