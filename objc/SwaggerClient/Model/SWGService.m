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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"_id": @"id", @"type": @"type", @"priority": @"priority", @"name": @"name", @"address": @"address", @"duration": @"duration", @"timeWindows": @"time_windows", @"size": @"size", @"requiredSkills": @"required_skills", @"allowedVehicles": @"allowed_vehicles" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"_id", @"type", @"priority", @"name", @"address", @"duration", @"timeWindows", @"size", @"requiredSkills", @"allowedVehicles"];
  return [optionalProperties containsObject:propertyName];
}

@end
