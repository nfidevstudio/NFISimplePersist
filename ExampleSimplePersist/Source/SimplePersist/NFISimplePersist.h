//
//  NFISimplePersist.h
//  ExampleSimplePersist
//
//  Created by José Carlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^SaveObjectsCompletionBlock)(BOOL success);

@interface NFISimplePersist : NSObject

#pragma mark - Instance.

/** Unique shared instance for NFISimplePersist.
 */
+ (instancetype)standarSimplePersist;

#pragma mark - Persist method

/**
 *  Persist the object
 */
- (void)saveObject:(id)object withKey:(NSString *)key;

/**
 * Persist an array of objects.
 *
 * @params key - This represent the property name of the key to save in the data base (The property ALWAYS must be a NSString). i.e (for save the user.id => @"id").
 *
 * All the objects will be saved with the same key
 */
- (void)saveObjects:(NSArray *)objects withKey:(NSString *)key andCompletionBlock:(SaveObjectsCompletionBlock)completionBlock;

#pragma mark - Load methods

/**
 *  Load all objects
 */
- (NSArray *)loadAllObjects;

/**
 *  Load all objects with the same class
 */
- (NSArray *)loadAllObjectsWithClass:(Class)class;

/**
 *  Load the object with the given key and class. Return nil if the table is empty
 */
- (id)loadObjectWithKey:(NSString *)key andClass:(Class)class;


#pragma mark - Remove methods

/**
 *  Remove object with the given key and class. Return a BOOL with the result
 */
- (BOOL)removeObjectWithKey:(NSString *)key andClass:(Class)class;

/**
 *  Remove object with the given class. Return a BOOL with the result
 */
- (BOOL)removeObjectsWithClass:(Class)class;

/**
 *  Remove all objects
 */
- (BOOL)removeAllObjects;

@end

