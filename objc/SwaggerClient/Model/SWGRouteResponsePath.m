#import "SWGRouteResponsePath.h"

@implementation SWGRouteResponsePath

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"distance": @"distance", @"time": @"time", @"ascend": @"ascend", @"descend": @"descend", @"points": @"points", @"pointsEncoded": @"points_encoded", @"bbox": @"bbox", @"snappedWaypoints": @"snapped_waypoints", @"instructions": @"instructions", @"details": @"details" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"distance", @"time", @"ascend", @"descend", @"points", @"pointsEncoded", @"bbox", @"snappedWaypoints", @"instructions", @"details"];
  return [optionalProperties containsObject:propertyName];
}

@end
