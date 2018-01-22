(ns graph-hopper-directions-api.api.solution
  (:require [graph-hopper-directions-api.core :refer [call-api check-required-params with-collection-format]])
  (:import (java.io File)))

(defn get-solution-with-http-info
  "Return the solution associated to the jobId
  This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent."
  [key job-id ]
  (check-required-params key job-id)
  (call-api "/vrp/solution/{jobId}" :get
            {:path-params   {"jobId" job-id }
             :header-params {}
             :query-params  {"key" key }
             :form-params   {}
             :content-types ["application/json"]
             :accepts       ["application/json"]
             :auth-names    []}))

(defn get-solution
  "Return the solution associated to the jobId
  This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent."
  [key job-id ]
  (:data (get-solution-with-http-info key job-id)))

