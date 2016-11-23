CREATE TABLE IF NOT EXISTS civirule_rule (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  name VARCHAR(80) NULL,
  label VARCHAR(128) NULL,
  trigger_id INT UNSIGNED NULL,
  trigger_params TEXT NULL,
  is_active TINYINT NULL DEFAULT 1,
  created_date DATE NULL,
  created_user_id INT NULL,
  modified_date DATE NULL,
  modified_user_id INT NULL,
  PRIMARY KEY (id),
  UNIQUE INDEX id_UNIQUE (id ASC),
  INDEX fk_rule_trigger_idx (trigger_id ASC),
  CONSTRAINT fk_rule_trigger
    FOREIGN KEY (trigger_id)
    REFERENCES civirule_trigger (id)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci
