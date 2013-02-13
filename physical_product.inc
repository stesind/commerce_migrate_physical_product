<?php
class MigrateCommercePhysicalWeightFieldHandler extends MigrateFieldHandler {
  public function __construct() {
    $this->registerTypes(array('physical_weight'));
  }

  static function arguments($unit = NULL) {
    $arguments = array();
    if (!is_null($unit)) {
      $arguments['unit'] = $unit;
    }
    return $arguments;
  }

  public function prepare($entity, array $field_info, array $instance, array $values) {
    $migration = Migration::currentMigration();
    $arguments = (isset($values['arguments']))? $values['arguments']: array();
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);
    // Setup the standard Field API array for saving.
    $delta = 0;
    foreach ($values as $value) {
      $unit = isset($arguments['unit']) ? $arguments['unit'] : 'g';

      $return[$language][$delta]['weight'] = $value;
      $return[$language][$delta]['unit'] = $unit;
      $delta++;
    }
    if (!isset($return)) {
      $return = NULL;
    }
    return $return;
  }
}


