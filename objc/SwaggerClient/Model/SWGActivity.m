#import "SWGActivity.h"

@implementation SWGActivity

- (instancetype)init {
  self = [super init];
  if (self) {
    // initialize property's default value, if any
    
  }
  return self;
}


/**
 * Maps json key to property name.
 * This method is used by `JSONModel`.
 */
+ (JSONKeyMapper *)keyMapper {
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"type": @"type", @"_id": @"id", @"locationId": @"location_id", @"address": @"address", @"arrTime": @"arr_time", @"endTime": @"end_time", @"endDateTime": @"end_date_time", @"arrDateTime": @"arr_date_time", @"waitingTime": @"waiting_time", @"preparationTime": @"preparation_time", @"distance": @"distance", @"drivingTime": @"driving_time", @"loadBefore": @"load_before", @"loadAfter": @"load_after" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"type", @"_id", @"locationId", @"address", @"arrTime", @"endTime", @"endDateTime", @"arrDateTime", @"waitingTime", @"preparationTime", @"distance", @"drivingTime", @"loadBefore", @"loadAfter"];
  return [optionalProperties containsObject:propertyName];
}

@end
