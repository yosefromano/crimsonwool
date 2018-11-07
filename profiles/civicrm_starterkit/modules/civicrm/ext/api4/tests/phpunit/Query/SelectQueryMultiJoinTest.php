<?php

namespace Civi\Test\Api4\Query;

use Civi\Api4\Contact;
use Civi\Api4\Email;
use Civi\Test\Api4\UnitTestCase;

/**
 * Class SelectQueryMultiJoinTest
 * @package Civi\Test\Api4\Query
 * @group headless
 */
class SelectQueryMultiJoinTest extends UnitTestCase {
  public function setUpHeadless() {
    $this->cleanup(['tablesToTruncate' => ['civicrm_contact', 'civicrm_email']]);
    $this->loadDataSet('MultiContactMultiEmail');
    return parent::setUpHeadless();
  }

  public function testOneToManySelect() {
    $results = Contact::get()
      ->addSelect('emails.email')
      ->execute()
      ->indexBy('id')
      ->getArrayCopy();

    $firstContactId = $this->getReference('test_contact_1')['id'];
    $secondContactId = $this->getReference('test_contact_2')['id'];

    $firstContact = $results[$firstContactId];
    $secondContact = $results[$secondContactId];
    $firstContactEmails = array_column($firstContact['emails'], 'email');
    $secondContactEmails = array_column($secondContact['emails'], 'email');

    $expectedFirstEmails = [
    'test_contact_one_home@fakedomain.com',
    'test_contact_one_work@fakedomain.com',
    ];
    $expectedSecondEmails = [
      'test_contact_two_home@fakedomain.com',
      'test_contact_two_work@fakedomain.com',
    ];

    $this->assertEquals($expectedFirstEmails, $firstContactEmails);
    $this->assertEquals($expectedSecondEmails, $secondContactEmails);
  }

  public function testManyToOneSelect() {
    $results = Email::get()
      ->addSelect('contact.display_name')
      ->execute()
      ->indexBy('id')
      ->getArrayCopy();

    $firstEmail = $this->getReference('test_email_1');
    $secondEmail = $this->getReference('test_email_2');
    $thirdEmail = $this->getReference('test_email_3');
    $fourthEmail = $this->getReference('test_email_4');
    $firstContactEmailIds = [$firstEmail['id'], $secondEmail['id']];
    $secondContactEmailIds = [$thirdEmail['id'], $fourthEmail['id']];

    foreach ($results as $id => $email) {
      $displayName = $email['contact']['display_name'];
      if (in_array($id, $firstContactEmailIds)) {
        $this->assertEquals('First Contact', $displayName);
      }
      elseif (in_array($id, $secondContactEmailIds)) {
        $this->assertEquals('Second Contact', $displayName);
      }
    }
  }

}
