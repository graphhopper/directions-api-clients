#import "OAIVehicleType.h"

@implementation OAIVehicleType

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"typeId": @"type_id", @"profile": @"profile", @"capacity": @"capacity", @"speedFactor": @"speed_factor", @"serviceTimeFactor": @"service_time_factor", @"costPerMeter": @"cost_per_meter", @"costPerSecond": @"cost_per_second", @"costPerActivation": @"cost_per_activation" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"typeId", @"profile", @"capacity", @"speedFactor", @"serviceTimeFactor", @"costPerMeter", @"costPerSecond", @"costPerActivation"];
  return [optionalProperties containsObject:propertyName];
}

@end
