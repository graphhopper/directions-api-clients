# GraphHopper Directions API
# 
# You use the GraphHopper Directions API to add route planning, navigation and route optimization to your software. E.g. the Routing API has turn instructions and elevation data and the Route Optimization API solves your logistic problems and supports various constraints like time window and capacity restrictions. Also it is possible to get all distances between all locations with our fast Matrix API.
# 
# OpenAPI spec version: 1.0.0
# 
# Generated by: https://github.com/swagger-api/swagger-codegen.git


#' Activity Class
#'
#' @field type 
#' @field id 
#' @field location_id 
#' @field address 
#' @field arr_time 
#' @field end_time 
#' @field end_date_time 
#' @field arr_date_time 
#' @field waiting_time 
#' @field preparation_time 
#' @field distance 
#' @field driving_time 
#' @field load_before 
#' @field load_after 
#'
#' @importFrom R6 R6Class
#' @importFrom jsonlite fromJSON toJSON
#' @export
Activity <- R6::R6Class(
  'Activity',
  public = list(
    `type` = NULL,
    `id` = NULL,
    `location_id` = NULL,
    `address` = NULL,
    `arr_time` = NULL,
    `end_time` = NULL,
    `end_date_time` = NULL,
    `arr_date_time` = NULL,
    `waiting_time` = NULL,
    `preparation_time` = NULL,
    `distance` = NULL,
    `driving_time` = NULL,
    `load_before` = NULL,
    `load_after` = NULL,
    initialize = function(`type`, `id`, `location_id`, `address`, `arr_time`, `end_time`, `end_date_time`, `arr_date_time`, `waiting_time`, `preparation_time`, `distance`, `driving_time`, `load_before`, `load_after`){
      if (!missing(`type`)) {
        stopifnot(is.character(`type`), length(`type`) == 1)
        self$`type` <- `type`
      }
      if (!missing(`id`)) {
        stopifnot(is.character(`id`), length(`id`) == 1)
        self$`id` <- `id`
      }
      if (!missing(`location_id`)) {
        stopifnot(is.character(`location_id`), length(`location_id`) == 1)
        self$`location_id` <- `location_id`
      }
      if (!missing(`address`)) {
        stopifnot(R6::is.R6(`address`))
        self$`address` <- `address`
      }
      if (!missing(`arr_time`)) {
        stopifnot(is.numeric(`arr_time`), length(`arr_time`) == 1)
        self$`arr_time` <- `arr_time`
      }
      if (!missing(`end_time`)) {
        stopifnot(is.numeric(`end_time`), length(`end_time`) == 1)
        self$`end_time` <- `end_time`
      }
      if (!missing(`end_date_time`)) {
        stopifnot(is.character(`end_date_time`), length(`end_date_time`) == 1)
        self$`end_date_time` <- `end_date_time`
      }
      if (!missing(`arr_date_time`)) {
        stopifnot(is.character(`arr_date_time`), length(`arr_date_time`) == 1)
        self$`arr_date_time` <- `arr_date_time`
      }
      if (!missing(`waiting_time`)) {
        stopifnot(is.numeric(`waiting_time`), length(`waiting_time`) == 1)
        self$`waiting_time` <- `waiting_time`
      }
      if (!missing(`preparation_time`)) {
        stopifnot(is.numeric(`preparation_time`), length(`preparation_time`) == 1)
        self$`preparation_time` <- `preparation_time`
      }
      if (!missing(`distance`)) {
        stopifnot(is.numeric(`distance`), length(`distance`) == 1)
        self$`distance` <- `distance`
      }
      if (!missing(`driving_time`)) {
        stopifnot(is.numeric(`driving_time`), length(`driving_time`) == 1)
        self$`driving_time` <- `driving_time`
      }
      if (!missing(`load_before`)) {
        stopifnot(is.list(`load_before`), length(`load_before`) != 0)
        lapply(`load_before`, function(x) stopifnot(is.character(x)))
        self$`load_before` <- `load_before`
      }
      if (!missing(`load_after`)) {
        stopifnot(is.list(`load_after`), length(`load_after`) != 0)
        lapply(`load_after`, function(x) stopifnot(is.character(x)))
        self$`load_after` <- `load_after`
      }
    },
    toJSON = function() {
      ActivityObject <- list()
      if (!is.null(self$`type`)) {
        ActivityObject[['type']] <- self$`type`
      }
      if (!is.null(self$`id`)) {
        ActivityObject[['id']] <- self$`id`
      }
      if (!is.null(self$`location_id`)) {
        ActivityObject[['location_id']] <- self$`location_id`
      }
      if (!is.null(self$`address`)) {
        ActivityObject[['address']] <- self$`address`$toJSON()
      }
      if (!is.null(self$`arr_time`)) {
        ActivityObject[['arr_time']] <- self$`arr_time`
      }
      if (!is.null(self$`end_time`)) {
        ActivityObject[['end_time']] <- self$`end_time`
      }
      if (!is.null(self$`end_date_time`)) {
        ActivityObject[['end_date_time']] <- self$`end_date_time`
      }
      if (!is.null(self$`arr_date_time`)) {
        ActivityObject[['arr_date_time']] <- self$`arr_date_time`
      }
      if (!is.null(self$`waiting_time`)) {
        ActivityObject[['waiting_time']] <- self$`waiting_time`
      }
      if (!is.null(self$`preparation_time`)) {
        ActivityObject[['preparation_time']] <- self$`preparation_time`
      }
      if (!is.null(self$`distance`)) {
        ActivityObject[['distance']] <- self$`distance`
      }
      if (!is.null(self$`driving_time`)) {
        ActivityObject[['driving_time']] <- self$`driving_time`
      }
      if (!is.null(self$`load_before`)) {
        ActivityObject[['load_before']] <- self$`load_before`
      }
      if (!is.null(self$`load_after`)) {
        ActivityObject[['load_after']] <- self$`load_after`
      }

      ActivityObject
    },
    fromJSON = function(ActivityJson) {
      ActivityObject <- jsonlite::fromJSON(ActivityJson)
      if (!is.null(ActivityObject$`type`)) {
        self$`type` <- ActivityObject$`type`
      }
      if (!is.null(ActivityObject$`id`)) {
        self$`id` <- ActivityObject$`id`
      }
      if (!is.null(ActivityObject$`location_id`)) {
        self$`location_id` <- ActivityObject$`location_id`
      }
      if (!is.null(ActivityObject$`address`)) {
        addressObject <- Address$new()
        addressObject$fromJSON(jsonlite::toJSON(ActivityObject$address, auto_unbox = TRUE))
        self$`address` <- addressObject
      }
      if (!is.null(ActivityObject$`arr_time`)) {
        self$`arr_time` <- ActivityObject$`arr_time`
      }
      if (!is.null(ActivityObject$`end_time`)) {
        self$`end_time` <- ActivityObject$`end_time`
      }
      if (!is.null(ActivityObject$`end_date_time`)) {
        self$`end_date_time` <- ActivityObject$`end_date_time`
      }
      if (!is.null(ActivityObject$`arr_date_time`)) {
        self$`arr_date_time` <- ActivityObject$`arr_date_time`
      }
      if (!is.null(ActivityObject$`waiting_time`)) {
        self$`waiting_time` <- ActivityObject$`waiting_time`
      }
      if (!is.null(ActivityObject$`preparation_time`)) {
        self$`preparation_time` <- ActivityObject$`preparation_time`
      }
      if (!is.null(ActivityObject$`distance`)) {
        self$`distance` <- ActivityObject$`distance`
      }
      if (!is.null(ActivityObject$`driving_time`)) {
        self$`driving_time` <- ActivityObject$`driving_time`
      }
      if (!is.null(ActivityObject$`load_before`)) {
        self$`load_before` <- ActivityObject$`load_before`
      }
      if (!is.null(ActivityObject$`load_after`)) {
        self$`load_after` <- ActivityObject$`load_after`
      }
    },
    toJSONString = function() {
       sprintf(
        '{
           "type": %s,
           "id": %s,
           "location_id": %s,
           "address": %s,
           "arr_time": %d,
           "end_time": %d,
           "end_date_time": %s,
           "arr_date_time": %s,
           "waiting_time": %d,
           "preparation_time": %d,
           "distance": %d,
           "driving_time": %d,
           "load_before": [%s],
           "load_after": [%s]
        }',
        self$`type`,
        self$`id`,
        self$`location_id`,
        self$`address`$toJSON(),
        self$`arr_time`,
        self$`end_time`,
        self$`end_date_time`,
        self$`arr_date_time`,
        self$`waiting_time`,
        self$`preparation_time`,
        self$`distance`,
        self$`driving_time`,
        lapply(self$`load_before`, function(x) paste(paste0('"', x, '"'), sep=",")),
        lapply(self$`load_after`, function(x) paste(paste0('"', x, '"'), sep=","))
      )
    },
    fromJSONString = function(ActivityJson) {
      ActivityObject <- jsonlite::fromJSON(ActivityJson)
      self$`type` <- ActivityObject$`type`
      self$`id` <- ActivityObject$`id`
      self$`location_id` <- ActivityObject$`location_id`
      AddressObject <- Address$new()
      self$`address` <- AddressObject$fromJSON(jsonlite::toJSON(ActivityObject$address, auto_unbox = TRUE))
      self$`arr_time` <- ActivityObject$`arr_time`
      self$`end_time` <- ActivityObject$`end_time`
      self$`end_date_time` <- ActivityObject$`end_date_time`
      self$`arr_date_time` <- ActivityObject$`arr_date_time`
      self$`waiting_time` <- ActivityObject$`waiting_time`
      self$`preparation_time` <- ActivityObject$`preparation_time`
      self$`distance` <- ActivityObject$`distance`
      self$`driving_time` <- ActivityObject$`driving_time`
      self$`load_before` <- ActivityObject$`load_before`
      self$`load_after` <- ActivityObject$`load_after`
    }
  )
)
