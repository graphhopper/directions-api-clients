#import "SWGVehicle.h"

@implementation SWGVehicle

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"vehicleId": @"vehicle_id", @"typeId": @"type_id", @"startAddress": @"start_address", @"endAddress": @"end_address", @"_break": @"break", @"returnToDepot": @"return_to_depot", @"earliestStart": @"earliest_start", @"latestEnd": @"latest_end", @"skills": @"skills" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"vehicleId", @"typeId", @"startAddress", @"endAddress", @"_break", @"returnToDepot", @"earliestStart", @"latestEnd", @"skills"];
  return [optionalProperties containsObject:propertyName];
}

@end
