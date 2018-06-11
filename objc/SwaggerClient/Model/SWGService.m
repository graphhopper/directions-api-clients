#import "SWGService.h"

@implementation SWGService

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"_id": @"id", @"type": @"type", @"priority": @"priority", @"name": @"name", @"address": @"address", @"duration": @"duration", @"preparationTime": @"preparation_time", @"timeWindows": @"time_windows", @"size": @"size", @"requiredSkills": @"required_skills", @"allowedVehicles": @"allowed_vehicles", @"disallowedVehicles": @"disallowed_vehicles", @"maxTimeInVehicle": @"max_time_in_vehicle" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"_id", @"type", @"priority", @"name", @"address", @"duration", @"preparationTime", @"timeWindows", @"size", @"requiredSkills", @"allowedVehicles", @"disallowedVehicles", @"maxTimeInVehicle"];
  return [optionalProperties containsObject:propertyName];
}

@end
