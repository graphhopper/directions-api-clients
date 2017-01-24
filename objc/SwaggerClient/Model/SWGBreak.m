#import "SWGBreak.h"

@implementation SWGBreak

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"earliest": @"earliest", @"latest": @"latest", @"duration": @"duration", @"maxDrivingTime": @"max_driving_time", @"initialDrivingTime": @"initial_driving_time", @"possibleSplit": @"possible_split" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"earliest", @"latest", @"duration", @"maxDrivingTime", @"initialDrivingTime", @"possibleSplit"];
  return [optionalProperties containsObject:propertyName];
}

@end
