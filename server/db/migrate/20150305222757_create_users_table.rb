require_relative "../../environment.rb"

class CreateUsersTable < ActiveRecord::Migration
	def up
		create_table :users do |t|
			t.string :username
			t.string :password
			t.bigint :total_keys_pressed
		end
	end

	def down
		drop_table :users
	end
end