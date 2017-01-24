#import "SWGSolution.h"

@implementation SWGSolution

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"costs": @"costs", @"distance": @"distance", @"time": @"time", @"transportTime": @"transport_time", @"maxOperationTime": @"max_operation_time", @"waitingTime": @"waiting_time", @"noVehicles": @"no_vehicles", @"noUnassigned": @"no_unassigned", @"routes": @"routes", @"unassigned": @"unassigned" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"costs", @"distance", @"time", @"transportTime", @"maxOperationTime", @"waitingTime", @"noVehicles", @"noUnassigned", @"routes", @"unassigned"];
  return [optionalProperties containsObject:propertyName];
}

@end
